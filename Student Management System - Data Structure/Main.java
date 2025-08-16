package StudentRecordManagement;

public class Main {
	

	    public static void main(String[] args) {
	        StudentRecordManagement records = new StudentRecordManagement();
	        records.createRecord("Tahmid Tafsir", 101, "Computer Science", 95);
	        records.createRecord("Md Sazid", 103, "Mathematics", 88);
	        records.createRecord("Ahsan", 102, "Physics", 92);

	        records.showRecords();

	        records.searchRecord(103);

	        records.deleteRecord(101);

	        records.showRecords();
	    }
	}


