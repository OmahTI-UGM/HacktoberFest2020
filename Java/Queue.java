//package antrian;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Random;

class Node {

    int key;
    float serviceTime, waitTime;
    float arrivalTime;

    Node next;

    public Node(int key) {
        this.key = key;
        this.next = null;
    }
}

class Queue {

    Node rear, front;
    int capacity, size = 0, count = 0;

    public Queue(int capacity) {
        this.front = this.rear = null;
        this.capacity = capacity;
    }

    public Queue() {
    }

    void add(int key) {

        Node temp = new Node(key);

        if (this.rear == null) {
            this.front = this.rear = temp;
            this.size++;
            return;
        }

        this.rear.next = temp;
        this.rear = temp;
        this.size++;
    }

    void pop() {
        if (this.front == null) {
            return;
        }

        Node temp = this.front;
        this.front = this.front.next;

        if (this.front == null) {
            this.rear = null;
        }
        this.size--;
    }
    float timeline;
    public static PriorityQueue<Event> pQueue = new PriorityQueue<Event>(20, new timelineComparator());
    static boolean idle = true;
    static int cust = 0;
    static Queue a = new Queue(7);

    void addEvent(double t, int e) {
        Event event2 = new Event(t, e);
        pQueue.add(event2);
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double arrival_rate = 0.5;
        a.timeline = (float) -(Math.log(1 - rand.nextFloat()) / arrival_rate);
        a.addEvent(a.timeline, 1);

        /* Jumlah Customer = 30 */
        while (a.cust < 30) {
            a.pQueue.poll().getAction();
        }
    }

    public static class Event {

        Random rand = new Random();
        public double time;
        public int action;
        public double arrival_rate = 0.5;

        public Event(double time, int action) {
            this.time = time;
            this.action = action;
        }

        public void setTime(float time) {
            this.time = time;
        }

        public void setAction(int action) {
            this.action = action;
        }

        public double getTime() {
            return this.time;
        }

        public void getAction() {
            switch (action) {
                case 1:
                    arrival();
                    break;
                case 2:
                    startServe();
                    break;
                default:
                    stopServe();
                    break;
            }

        }

        public void arrival() {
            Random rand = new Random();
            if (a.size <= a.capacity) {
                a.add(1);
                System.out.println("Customer masuk pada " + this.time);

                /* Exponential Distribution */
                double t = this.time - (Math.log(1 - rand.nextFloat()) / arrival_rate);

                if (idle) {
                    Event event2 = new Event(this.time, 2);
                    a.pQueue.add(event2);
                }
                a.addEvent(t, 1);
            }
        }

        public void startServe() {
            Random rand = new Random();
            if (idle) {
                idle = false;
            }
            a.pop();

            /* Exponential Distribution */
            double t2 = this.time - (Math.log(1 - rand.nextFloat()) / arrival_rate);

            Event event3 = new Event(t2, 3);
            pQueue.add(event3);

            System.out.println("Customer dilayani pada " + this.time);
        }

        public void stopServe() {
            if (a.size > 0) {
                Event event2 = new Event(this.time, 2);
                pQueue.add(event2);

            } else {
                idle = true;
            }
            cust++;
            System.out.println("Customer keluar pada " + this.time);
        }
    }

    static class timelineComparator implements Comparator<Event> {

        @Override
        public int compare(Event e1, Event e2) {
            if (e1.time > e2.time) {
                return 1;
            } else if (e1.time < e2.time) {
                return -1;
            }
            return 0;
        }
    }

}
