package scheduler;

import java.util.HashMap;
import java.util.LinkedList;


public class Scheduler  {

    private HashMap<JobId, Job> jobs;
    private LinkedList<User> users;
    
    public Scheduler() {
        jobs = new HashMap<>();
        users = new LinkedList<>();
    }

    public void addUser(User user) {
        users.add(user);
        users.sort(User::compareTo);
    }
    
    public JobId addJob(String execFile, int maxSpan, String userId){
        Job job = new Job(execFile, maxSpan);
        jobs.put(job.getJobId(), job);
        users.stream().filter(user -> user.getId().equals(userId)).forEach(user -> user.addJob(job));
        users.sort(User::compareTo);
        return job.getJobId();
    }

    public Job getJob(JobId id){
        return jobs.get(id);
    }

    public Job extractNextJobToSchedule() {
        User user = users.poll();
        while(user != null && user.isEmpty()) {
            user = users.poll();
        }
        if(user != null) {
            users.add(user);
            return user.extractNextJob();
        }
        return null;
    }

}
