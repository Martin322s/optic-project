# Optic/Suppliers - project
Technical University - Sofia - OOP Project

## Description of the application development
- An application to maintain information about suppliers of
different materials from optics. It works with suppliers for which
their Bulstat, name and location must be stored
and phone number. Each supplier can supply one or
more optics that are characterized by type, thickness, diopter and
the name of the material.
- The application has the ability to enter any number
different suppliers and optics, there is a choice of
supplier and to order various materials from him, such as
calculates the total price of the order. Classes encapsulate
all the details. Private instances of the variables are used
to store the various details. There are at least two
constructor default and with parameters, public getters/setters for private
the instances of the variables.
- Validation of input data is performed as is
redefined the << operation, which is used to output the
the data. The data is read and stored in a file named
submitted by the user. Classes are described with UML class diagrams.
- Data is entered dynamically, through a menu.

## List of functions and used inputs and outputs data
- This program is designed to manage a list of suppliers
and their optics. It allows the user to add
suppliers and optics, to show the list of suppliers, yes
calculate the price of an order and save the list of suppliers in
file.
- The program is implemented using three classes: Optic, Supplier and
SupplierManager.
- The optical class represents an optical lens or component with
properties such as type, thickness, diopter and material. The class
Provider represents an optics provider, with properties such as
name, bulstat (Bulgarian identification number),
location, phone number and optics vector. The class
SupplierManager manages a list of suppliers and provides
methods to add providers and optics, display of
suppliers, calculate the price of an order and save the
the list of suppliers in a file.
- The main function provides a simple menu to interact with
SupplierManager. User can add suppliers and
optics, to display a list of suppliers, to calculate the price of
order and keep the supplier list on file. The program is
designed to be interactive and easy to use, with clear
prompts and feedback.

## A description of the architecture, classes, and relationships between them
