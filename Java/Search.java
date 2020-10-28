import java.util.Scanner;
import java.io.IOException;
import java.util.ArrayList;

class Node{
    int value;
    Node next;

    Node (int id){
        this.value=id;
    }

    public void displayLink(){
        System.out.print("("+this.value+")");
    }
}

class LinkedList {
    Node head;
    Node tail;

    LinkedList() {
        head = null; //tidak ada items di dalam list
        tail = null;
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

    public void insertFirst(int id) {
        Node node = new Node(id); //buat objek dari Node
        node.next = head; //pointer untuk node baru diarahkan ke first node
        head = node; //head (node pertama) = node baru
        if (tail == null) { //cek kondisi apakah list kosong
            tail = head;
        }
    }
    
    public void search(int id){
        Node current = head;
        int indeks=0;
        ArrayList<Integer> arr=new ArrayList<>();
        while(current!=null){
            if(current.value==id) arr.add(indeks);
            current = current.next;
            indeks++;
        }
        if(arr.isEmpty()) {
        	System.out.println("Tidak ada dalam list");
        	return;
        }
        System.out.print("\nValue "+id+" Berada pada indeks:");
        for(int i : arr) System.out.print(" "+i);
    }
}


public class Main {
    public static void main(String[] args) throws IOException {
        Node head = null;
        LinkedList theList1 = new LinkedList(); //buat list baru

        for(int i=10;i>=0;i--){
            theList1.insertFirst(i);
        }
        theList1.insertFirst(5);
		theList1.insertFirst(3);
        theList1.displayList();
       
		int a;
		Scanner input = new Scanner(System.in);
		while(true){
			System.out.print("\nMasukkan angka yang ingin dicari: ");
			a = input.nextInt();
			if(a==9999)break;
			theList1.search(a);
			
		}
    }
}