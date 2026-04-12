public class ThreadSafeEagerSingleton {
    private static ThreadSafeEagerSingleton instance = new ThreadSafeEagerSingleton();

    private ThreadSafeEagerSingleton() {
        System.out.println("Singleton Constructor Called!");
    }

    public static ThreadSafeEagerSingleton getInstance() {
        return instance;
    }

    public static void main(String[] args) {
        ThreadSafeEagerSingleton s1 = ThreadSafeEagerSingleton.getInstance();
        ThreadSafeEagerSingleton s2 = ThreadSafeEagerSingleton.getInstance();

        System.out.println(s1 == s2);
    }
}

//  In this implementation, the Singleton instance is created at the time of class loading,
//  ensuring thread safety without the need for synchronization.
//  However, it may lead to resource wastage if the instance is never used.