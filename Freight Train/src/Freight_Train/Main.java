package Freight_Train;

public class Main {

	  public static void main(String[] args) {
	    System.out.println("1. Test the default constructor FreightTrain()");
	    FreightTrain train1 = new FreightTrain();
	    System.out.println("Printing FreightTrain():\n" + train1 + "\n");

	    System.out.println("\n2. Test the constructor FreightTrain(n)");
	    FreightTrain emptyTrain = new FreightTrain(0);
	    System.out.println("Printing emptyTrain (n=0):\n" + emptyTrain + "\n");
	    FreightTrain negativeTrain = new FreightTrain(-7);
	    System.out.println("Printing negativeTrain (n=-7):\n" + emptyTrain + "\n");
	    FreightTrain trainWithFiveCars = new FreightTrain(5);
	    System.out.println("Printing trainWithFiveCars (n=5):\n" + trainWithFiveCars + "\n");

	    System.out.println("\n3. Test setCargo(String)");
	    
	    trainWithFiveCars.setCargo("gadgets");
	    System.out.println("Printing trainWithFiveCars with cargo now gadgets:\n" + trainWithFiveCars + "\n");
	    
	    trainWithFiveCars.setCargo("onions");
	    System.out.println("Printing trainWithFiveCars with cargo of onions (back to gizmos):\n" + trainWithFiveCars + "\n");

	    System.out.println("\n4. Test fillTrain()");
	    
	    trainWithFiveCars.fillTrain();
	    System.out.println("Printing trainWithFiveCars with all Boxcars full:\n" + trainWithFiveCars + "\n");

	    System.out.println("\n5. Test callForRepair(n)");
	    
	    trainWithFiveCars.callForRepair(1);
	    System.out.println("Printing trainWithFiveCars with second car in repair:\n" + trainWithFiveCars + "\n");

	    System.out.println("\n6. Test setMultiCargo()");
	    
	    FreightTrain trainWithEightCars = new FreightTrain(8);
	    trainWithEightCars.setMultiCargo();
	    System.out.println("Printing multi Cargo 8-car train:\n" + trainWithEightCars + "\n");

	  }
	}

