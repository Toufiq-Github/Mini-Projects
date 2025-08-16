/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospitalmanagementsystem;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

class HospitalManagementSystem {
    List<Patient> patients;
    List<Doctor> doctors;
    private List<Appointment> appointments;

    public HospitalManagementSystem() {
        patients = new ArrayList<>();
        doctors = new ArrayList<>();
        appointments = new ArrayList<>();
    }

    public void addPatient(String name, int age, String gender, String contact) {
        Patient patient = new Patient(name, age, gender, contact);
        patients.add(patient);
        System.out.println("Patient added successfully.");
    }

    public void addDoctor(String name, int age, String gender, String specialization, String contact) {
        Doctor doctor = new Doctor(name, age, gender, specialization, contact);
        doctors.add(doctor);
        System.out.println("Doctor added successfully.");
    }

    public void scheduleAppointment(int patientIndex, int doctorIndex, String dateTime) {
        if (patientIndex >= 0 && patientIndex < patients.size() && doctorIndex >= 0 && doctorIndex < doctors.size()) {
            Patient patient = patients.get(patientIndex);
            Doctor doctor = doctors.get(doctorIndex);
            Appointment appointment = new Appointment(patient, doctor, dateTime);
            appointments.add(appointment);
            System.out.println("Appointment scheduled successfully.");
        } else {
            System.out.println("Invalid patient or doctor index.");
        }
    }

    public void displayAppointments() {
        System.out.println("Scheduled Appointments");
        System.out.println("----------------------");
        for (int i = 0; i < appointments.size(); i++) {
            Appointment appointment = appointments.get(i);
            System.out.println("Appointment " + (i + 1) + ":");
            appointment.display();
        }
    }

    public void saveDataToFile(String filename) {
        try (FileOutputStream fos = new FileOutputStream(filename);
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(patients);
            oos.writeObject(doctors);
            oos.writeObject(appointments);
            System.out.println("Data saved to file successfully.");
        } catch (IOException e) {
            System.out.println("Error saving data to file: " + e.getMessage());
        }
    }

    public void loadDataFromFile(String filename) {
        try (FileInputStream fis = new FileInputStream(filename);
             ObjectInputStream ois = new ObjectInputStream(fis)) {
            patients = (List<Patient>) ois.readObject();
            doctors = (List<Doctor>) ois.readObject();
            appointments = (List<Appointment>) ois.readObject();
            System.out.println("Data loaded from file successfully.");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error loading data from file: " + e.getMessage());
        }
    }
}
