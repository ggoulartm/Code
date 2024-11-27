package scheduler;

import java.util.PriorityQueue;

public class User implements Comparable<User> {
    private String id;
    private Score score;
    private PriorityQueue<Job> jobs;
    
    public User(String id, Score score) {
        this.id = id;
        this.score = score;
        this.jobs = new PriorityQueue<>();
    }

    public String getId() {
        return this.id;
    }

    public void addJob(Job job) {
        jobs.add(job);
    }

    public Job extractNextJob() {
        return jobs.poll();
    }
    
    public boolean isEmpty() {
        return jobs.isEmpty();
    }

    public Score getScore() {
        return this.score;
    }

    @Override
    public int compareTo(User other) {
        return this.score.compareTo(other.getScore());
    }
}
