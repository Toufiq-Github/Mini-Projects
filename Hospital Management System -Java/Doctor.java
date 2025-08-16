/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospitalmanagementsystem;

class Doctor extends Person {
    private final String specialization;
    private final String contact;

    public Doctor(String name, int age, String gender, String specialization, String contact) {
        super(name, age, gender);
        this.specialization = specialization;
        this.contact = contact;
    }

    public String getSpecialization() {
        return specialization;
    }

    public String getContact() {
        return contact;
    }

    public void display() {
        super.display();
        System.out.println("Specialization: " + specialization);
        System.out.println("Contact: " + contact);
    }
}
