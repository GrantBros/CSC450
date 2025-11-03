package project_portfolio_Java;

import java.util.concurrent.locks.ReentrantLock;

public class ConcurrentCounter {
	private static final ReentrantLock consoleLock = new ReentrantLock();
	
	private static void countUp(int limit) {
		long startTime = System.currentTimeMillis();
		
		for (int i =1; i <= limit; i++) {
			consoleLock.lock();
			try {
				System.out.println("Counting up: " + i);
			} finally {
				consoleLock.unlock();
			}
			try { 
				Thread.sleep(100);
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
				return;
			}
		}
		
		long endTime = System.currentTimeMillis();
		double elapsed = (endTime - startTime) / 1000.0;
		
		consoleLock.lock();
		try {
			System.out.printf("Thread 1 completed in %.3f seconds. %n", elapsed);
		} finally {
			consoleLock.unlock();
	}
	}
	private static void countDown(int start) {
		long startTime = System.currentTimeMillis();
		
		for (int i = start; i >= 0; i--) {
			consoleLock.lock();
			try {
				System.out.println("Counting Down: " +i);
			} finally {
				consoleLock.unlock();
			}
			
			try {
				Thread.sleep(100);;
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
			return;
		}
	}
	
	long endTime = System.currentTimeMillis();
	double elapsed = (endTime - startTime) / 1000.0;
	
	consoleLock.lock();
	try {
		System.out.printf("Thread 2 completed in %.3f seconds.%n", elapsed);
	} finally {
		consoleLock.unlock();
		}
	}

	public static void main(String[] args) {
		System.out.println("Starting concurrent counting exercise...");
		
		Thread threadUp = new Thread(() -> countUp(20));
		Thread threadDown = new Thread(() -> countDown(20));
		
		threadUp.start();
		threadDown.start();
		
	try {
		threadUp.join();
		threadDown.join();
	} catch (InterruptedException e) {
		Thread.currentThread().interrupt();
	}
		System.out.println("Both threads have finished execution.");
	}
}
