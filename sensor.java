package hoops;

public class sensor {
	boolean value ;
	private boolean[] test = {true, false };
	sensor(){
		int test1 = (int)  Math.abs(Math.random()*100);
		int lol = 0 ;
		if(test1 <= 50) {
			lol = 0 ;
		}
		else {
			lol = 1 ;
		}
		value =  test[lol];
	}
	

}
