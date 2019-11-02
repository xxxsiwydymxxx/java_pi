import java.util.concurrent.Semaphore;

public class Zad_EP {

    private static int A = 0;
    private static int B = 0;
    private static int C = 3;
    
    private static final Semaphore PSEM = new Semaphore(0, true);

    public static void main(String[] args) {
        new P1().start();
        new P2().start();
        new P3().start();
        new P4().start();
    }

    private static final class P1 extends Thread {

        @Override
        public void run() {
            try {
//                PSEM.acquire();
                A = 10;
//                PSEM.acquire();
                B = B + 5;
//                PSEM.acquire();
                C = C + A; 
//                PSEM.acquire();

                Thread.sleep(0);
                System.out.println("Thread P1 is done...");

            } catch (InterruptedException ex) {
                System.out.println("Ooops...");
                Thread.currentThread().interrupt();
                throw new RuntimeException(ex);
            }
        }
    }

    private static final class P2 extends Thread {

        @Override
        public void run() {
            try {
//                PSEM.acquire();
                B = B + C;
//                PSEM.acquire(); 
                A = A + B;
//                PSEM.acquire();
                Thread.sleep(0);

                System.out.println("Thread P2 is done...");

            } catch (InterruptedException ex) {
                System.out.println("Ooops...");
                Thread.currentThread().interrupt();
                throw new RuntimeException(ex);
            }
        }
    }

    private static final class P3 extends Thread {

        @Override
        public void run() {
            try {
//                PSEM.acquire();
                C = B + 10;
//                PSEM.acquire();
                A = 2 * A;
//                PSEM.acquire();
                B = B + A;
//                PSEM.acquire();
                Thread.sleep(0);
                System.out.println("Thread P3 is done...");

            } catch (InterruptedException ex) {
                System.out.println("Ooops...");
                Thread.currentThread().interrupt();
                throw new RuntimeException(ex);
            }
        }
    }

    private static final class P4 extends Thread {

        @Override
        public void run() {
            try {

                System.out.println("Sum result: " + A + " + " + B + " + " + C + " = " + (A + B + C));
                PSEM.release(3);
                Thread.sleep(0);
                System.out.println("Thread P4 is done...");

            } catch (InterruptedException ex) {
                System.out.println("Ooops...");
                Thread.currentThread().interrupt();
                throw new RuntimeException(ex);
            }
        }
    }

    
}
