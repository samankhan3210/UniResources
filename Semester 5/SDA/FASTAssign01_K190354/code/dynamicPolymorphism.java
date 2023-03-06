package javaCodes;

class Animal {
	public void eat() {
		System.out.println("This animal eats insects.");
	}
}

class Bird extends Animal {

	public void eat() {
		System.out.println("This bird eats seeds.");
	}

}
class dynamicPolymorphism {
	
	public static void main( String [] args ) {
		Animal myAnimal = new Animal();
		myAnimal.eat();

		Bird myBird = new Bird();
		myBird.eat();	
		//System.out.println( "Hello World !!\n" );
	}
}
