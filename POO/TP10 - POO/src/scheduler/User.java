package scheduler;

import java.util.LinkedList;

public class User implements Comparable<User> {
    private String id;
    private Score score;
    private LinkedList<Job> jobs;
    
    public User(String id, Score score) {
        this.id = id;
        this.score = score;
        this.jobs = new LinkedList<>();
    }

    public String getId() {
        return this.id;
    }

    public void addJob(Job job) {
        jobs.add(job);
    }

    public Job extractNextJob() {
        this.score.increase();
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
        int compare = this.score.compareTo(other.getScore());
        if (compare == 0) {
            return -this.id.compareTo(other.getId());
        }
        return compare;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (other == null || this.getClass() != other.getClass()) {
            return false;
        }
        User otherUser = (User) other;
        return this.id.equals(otherUser.getId());
    }

    @Override
    public String toString() {
        return this.id + " (" + this.score + ")";
    }
}
