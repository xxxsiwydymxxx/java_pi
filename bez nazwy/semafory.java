import java.util.concurrent.Semaphore;
 /**
11 *
12 * @author ZTI
13 */
public class SemaphoresABC {
private static final int COUNT = 10; //Number of letters displayed by threads
private static final int DELAY = 5; //delay, in milliseconds, used to put a thread to sleep

 private static final Semaphore a = new Semaphore(1, true);
 private static final Semaphore b = new Semaphore(0, true);
 private static final Semaphore c = new Semaphore(0, true);

 public static void main(String[] args) {
 new A().start(); //runs a thread defined below
 new B().start();
 new C().start();

 }

 private static final class A extends Thread { //thread definition
     
     @Override
@SuppressWarnings("SleepWhileInLoop")
 public void run() {
 try {
 for (int i = 0; i < COUNT; i++) {
 //use semaphores here

 System.out.print("A ");
 //use semaphores here

 Thread.sleep(DELAY);
 }
 } catch (InterruptedException ex) {
 System.out.println("Ooops...");
 Thread.currentThread().interrupt();
 throw new RuntimeException(ex);
 }
 System.out.println("\nThread A: I'm done...");
 }
 }
 
private static final class B extends Thread {

 @Override
 @SuppressWarnings("SleepWhileInLoop")
 public void run() {
 try {
 for (int i = 0; i < COUNT; i++) {
 //use semaphores here

 System.out.print("B ");
 //use semaphores here

 Thread.sleep(DELAY);
 }
 } catch (InterruptedException ex) {
 System.out.println("Ooops...");
 Thread.currentThread().interrupt();
 throw new RuntimeException(ex);
 }
System.out.println("\nThread B: I'm done...");
 }
 }

 private static final class C extends Thread {

 @Override
 @SuppressWarnings("SleepWhileInLoop")
 public void run() {
 try {
 for (int i = 0; i < COUNT; i++) {
 //use semaphores here

 System.out.print("C ");
 //use semaphores here

 Thread.sleep(DELAY);
 }
 } catch (InterruptedException ex) {
 System.out.println("Ooops...");
 Thread.currentThread().interrupt();
 throw new RuntimeException(ex);
 }
 System.out.println("\nThread C: I'm done...");
 }
 }
 }
