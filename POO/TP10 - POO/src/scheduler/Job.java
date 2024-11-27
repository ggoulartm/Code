package scheduler;

public class Job implements Comparable<Job> {    
    private JobId jobId;
    private String execFile;
    private int maxSpan;
    private JobStatus status;

    public Job(String execFile, int maxSpan) {
        this.jobId = new JobId();
        this.execFile = execFile;
        this.maxSpan = maxSpan;
        this.status = JobStatus.PENDING;
    }

    public void start() {
        this.status = JobStatus.STARTED;
    }

    public JobId getJobId() {
        return this.jobId;
    }

    public JobStatus getStatus() {
        return this.status;
    }

    @Override
    public String toString() {
        return "<" + this.execFile + ", " + this.maxSpan + ">";
    }

    @Override
    public int compareTo(Job other) {
        return this.status.compareTo(other.getStatus());
    }

}
