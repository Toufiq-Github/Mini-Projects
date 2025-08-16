/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospitalmanagementsystem;

class Patient extends Person {
    private final String contact;

    public Patient(String name, int age, String gender, String contact) {
        super(name, age, gender);
        this.contact = contact;
    }

    public String getContact() {
        return contact;
    }

    public void display() {
        super.display();
        System.out.println("Contact: " + contact);
    }
}
