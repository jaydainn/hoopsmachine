package hoops;

import java.util.concurrent.TimeUnit;

public class hi {

	public static void main(String[] args) throws InterruptedException {
		sensor c = new sensor();
		timer d = new timer();
		@SuppressWarnings("unused")
		boolean gamestart;
		int score = 0;
		if (c.value == true) {
			score++;
			gamestart = true;

		}
		if (gamestart = true) {
			d.start();
			while (d.secondpassed < 30) {
				sensor e = new sensor();
				TimeUnit.MILLISECONDS.sleep(600);
				if (e.value == true) {
					score++;
					System.out.println("Score : " + score + " Time left : " + (30 - d.secondpassed));
				}
			}
			gamestart = false ;
			System.out.println("Game Over , Your score : "+score);
		}

	}

}
