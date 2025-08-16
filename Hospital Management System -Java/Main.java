/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospitalmanagementsystem;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            HospitalManagementSystem hospital = new HospitalManagementSystem();
            
            int choice;
            do {
                System.out.println("Hospital Management System");
                System.out.println("1. Add Patient");
                System.out.println("2. Add Doctor");
                System.out.println("3. Schedule Appointment");
                System.out.println("4. Display Appointments");
                System.out.println("5. Save Data to File");
                System.out.println("6. Load Data from File");
                System.out.println("7. Exit");
                System.out.print("Enter your choice: ");
                choice = scanner.nextInt();
                scanner.nextLine();  
                
                switch (choice) {
                    case 1:
                        System.out.print("Enter patient name: ");
                        String patientName = scanner.nextLine();
                        System.out.print("Enter patient age: ");
                        int patientAge = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Enter patient gender: ");
                        String patientGender = scanner.nextLine();
                        System.out.print("Enter patient contact: ");
                        String patientContact = scanner.nextLine();
                        hospital.addPatient(patientName, patientAge, patientGender, patientContact);
                        break;
                    case 2:
                        System.out.print("Enter doctor name: ");
                        String doctorName = scanner.nextLine();
                        System.out.print("Enter doctor age: ");
                        int doctorAge = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Enter doctor gender: ");
                        String doctorGender = scanner.nextLine();
                        System.out.print("Enter doctor specialization: ");
                        String doctorSpecialization = scanner.nextLine();
                        System.out.print("Enter doctor contact: ");
                        String doctorContact = scanner.nextLine();
                        hospital.addDoctor(doctorName, doctorAge, doctorGender, doctorSpecialization, doctorContact);
                        break;
                    case 3:
                        System.out.println("Available Patients:");
                        for (int i = 0; i < hospital.patients.size(); i++) {
                            System.out.println((i + 1) + ". " + hospital.patients.get(i).getName());
                        }
                        System.out.print("Select a patient (index): ");
                        int patientIndex = scanner.nextInt() - 1;
                        scanner.nextLine(); 
                        System.out.println("Available Doctors:");
                        for (int i = 0; i < hospital.doctors.size(); i++) {
                            System.out.println((i + 1) + ". " + hospital.doctors.get(i).getName());
                        }
                        System.out.print("Select a doctor (index): ");
                        int doctorIndex = scanner.nextInt() - 1;
                        scanner.nextLine(); 
                        System.out.print("Enter appointment date and time: ");
                        String dateTime = scanner.nextLine();
                        hospital.scheduleAppointment(patientIndex, doctorIndex, dateTime);
                        break;
                    case 4:
                        hospital.displayAppointments();
                        break;
                    case 5:
                        System.out.print("Enter filename to save data: ");
                        String saveFilename = scanner.nextLine();
                        hospital.saveDataToFile(saveFilename);
                        break;
                    case 6:
                        System.out.print("Enter filename to load data: ");
                        String loadFilename = scanner.nextLine();
                        hospital.loadDataFromFile(loadFilename);
                        break;
                    case 7:
                        System.out.println("Exiting...");
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
                
                System.out.println();
            } while (choice != 7);
        }
    }
}