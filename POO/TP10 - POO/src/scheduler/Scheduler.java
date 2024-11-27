package scheduler;

import java.util.HashMap;
import java.util.PriorityQueue;


public class Scheduler  {

    private HashMap<JobId, Job> jobs;
    private PriorityQueue<User> users;
    
    public Scheduler() {
        jobs = new HashMap<>();
        users = new PriorityQueue<>();
    }

    public void addUser(User user) {
        users.add(user);
    }
    
    public JobId addJob(String execFile, int maxSpan, String userId){
        Job job = new Job(execFile, maxSpan);
        jobs.put(job.getJobId(), job);
        users.stream().filter(user -> user.getId().equals(userId)).forEach(user -> user.addJob(job));
        return job.getJobId();
    }

    public Job getJob(JobId id){
        return jobs.get(id);
    }

    public Job extractNextJobToSchedule() {
        User user = users.peek();
        if(user != null){
            Job job = user.extractNextJob();
            if(user.isEmpty()){
                users.poll();
            }
            return job;
        }
        return null;
    }

}
