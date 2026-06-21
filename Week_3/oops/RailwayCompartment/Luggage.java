package Week_3.oops.RailwayCompartment;

public class Luggage extends Compartment {
    @Override
    public String notice() {
        return "Luggage Compartment: For storing heavy luggage and parcels. Maximum weight limit: 50kg per item.";
    }
}