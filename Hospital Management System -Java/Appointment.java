/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospitalmanagementsystem;

class Appointment {
    private final Patient patient;
    private final Doctor doctor;
    private final String dateTime;

    public Appointment(Patient patient, Doctor doctor, String dateTime) {
        this.patient = patient;
        this.doctor = doctor;
        this.dateTime = dateTime;
    }

    public Patient getPatient() {
        return patient;
    }

    public Doctor getDoctor() {
        return doctor;
    }

    public String getDateTime() {
        return dateTime;
    }

    public void display() {
        System.out.println("Appointment Details");
        System.out.println("-------------------");
        System.out.println("Patient:");
        patient.display();
        System.out.println("\nDoctor:");
        doctor.display();
        System.out.println("Date and Time: " + dateTime);
        System.out.println("-------------------");
    }
}
