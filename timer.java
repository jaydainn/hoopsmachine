package hoops;

import java.util.Timer;
import java.util.TimerTask;

public class timer {
	int secondpassed = 0 ;
	Timer mytimer = new Timer();
	TimerTask task = new TimerTask() {
		public void run() {
			secondpassed++;
			
		}
		
	};
	
	public void start() {
		mytimer.scheduleAtFixedRate(task,1000,1000);
		
	}
}
