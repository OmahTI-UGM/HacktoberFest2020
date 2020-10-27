import java.util.Scanner;
import java.io.IOException;

class Node{
    int value;
    Node next;
	Node prev;
    Node (int id){
        this.value=id;
    }

    public void displayLink(){
        System.out.print("("+this.value+")");
    }
}

class LinkedList {
    Node head;

    LinkedList() {
        head = null; //tidak ada items di dalam list
    }

    public void displayList() {
        System.out.print("List (first->last): ");
        Node current = head; //mulai dari awal list sampai akhir
        while (current != null) { //looping untuk mengecek masing-masing node
            current.displayLink(); //menampilkan data
            current = current.next; //pindah ke node berikutnya
        }
        System.out.println("");
    }

    public void insert(int id) {
        Node node = new Node(id); //buat objek dari Node
        if(head==null){
			node.prev=null;
			head = node;
			return;
		}
      	Node last = head;
      	while(last.next!=null){
			last=last.next;
        }
		last.next = node;
		node.prev = last;      
    }
	
	public void reverse(){
		Node current = head;
		Node depan = null;
		Node belakang = null;
		while(current!=null){
		    depan = current.next;
		    current.next=belakang;
		    if(belakang!=null)belakang.prev=current;
		    belakang = current;
		    current = depan;
		}
		this.head = belakang;
	}
}


public class Main {
    public static void main(String[] args) throws IOException {
        Node head = null;
        LinkedList theList1 = new LinkedList(); //buat list baru

        for(int i=10;i>=0;i--){
            theList1.insert(i);
        }
        theList1.displayList();
		
      	theList1.reverse();
		System.out.println("\nSetelah dibalik: "); 	
        theList1.displayList();
    }
}