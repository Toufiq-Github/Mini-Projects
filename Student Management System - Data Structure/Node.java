package StudentRecordManagement;

public class Node {
	

	    String name;
	    int rollNumber;
	    String course;
	    int totalMarks;
	    Node next;

	    public Node(String name, int rollNumber, String course, int totalMarks) {
	        this.name = name;
	        this.rollNumber = rollNumber;
	        this.course = course;
	        this.totalMarks = totalMarks;
	        this.next = null;
	    }
	}



