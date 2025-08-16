package StudentRecordManagement;

public class StudentRecordManagement {
	

	    private Node head;

	    public void checkRecord(int rollNumber) {
	        Node current = head;
	        while (current != null) {
	            if (current.rollNumber == rollNumber) {
	                System.out.println("Record already exists.");
	                return;
	            }
	            current = current.next;
	        }
	    }

	    public void createRecord(String name, int rollNumber, String course, int totalMarks) {
	        checkRecord(rollNumber);
	        Node newRecord = new Node(name, rollNumber, course, totalMarks);

	        if (head == null || rollNumber < head.rollNumber) {
	            newRecord.next = head;
	            head = newRecord;
	        } else {
	            Node current = head;
	            while (current.next != null && rollNumber > current.next.rollNumber) {
	                current = current.next;
	            }
	            newRecord.next = current.next;
	            current.next = newRecord;
	        }

	        System.out.println("Record created successfully.");
	    }

	    public void searchRecord(int rollNumber) {
	        Node current = head;
	        while (current != null) {
	            if (current.rollNumber == rollNumber) {
	                System.out.println("Record found - Name: " + current.name +
	                        ", Course: " + current.course +
	                        ", Total Marks: " + current.totalMarks);
	                return;
	            }
	            current = current.next;
	        }
	        System.out.println("Record not found.");
	    }

	    public void deleteRecord(int rollNumber) {
	        if (head != null && head.rollNumber == rollNumber) {
	            head = head.next;
	            System.out.println("Record deleted successfully.");
	            return;
	        }

	        Node current = head;
	        Node prev = null;
	        while (current != null && current.rollNumber != rollNumber) {
	            prev = current;
	            current = current.next;
	        }

	        if (current != null) {
	            prev.next = current.next;
	            System.out.println("Record deleted successfully.");
	        } else {
	            System.out.println("Record not found.");
	        }
	    }

	    public void showRecords() {
	        Node current = head;
	        while (current != null) {
	            System.out.println("Roll Number: " + current.rollNumber +
	                    ", Name: " + current.name +
	                    ", Course: " + current.course +
	                    ", Total Marks: " + current.totalMarks);
	            current = current.next;
	        }
	    }
	}


