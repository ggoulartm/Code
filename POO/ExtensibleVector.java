class ExtensibleVector {
    private Vector vec;
    private int size;
    private int capacity;
    public ExtensibleVector(int i) {
        this.vec = new Vector(2*i);
        this.size = 0;
        this.capacity = 2*i;
    }
    public Vector Get() {
        return this.vec;
    }
    public void append(Rational r) {
        if(this.size == this.capacity) {
            Vector tmpVec = this.vec;
            this.vec = new Vector(2*this.capacity);
            for(int i = 0; i < this.capacity; i++) {
                this.vec.Insert(tmpVec.get(i),i);
            }
            this.capacity *= 2;
        }
        this.vec[size]=r
                size++;
    }
    public int getDimension(
            return this.size;
    )
}