public class ThreadSafeLockingSingleton {
    private static ThreadSafeLockingSingleton instance = null;

    private ThreadSafeLockingSingleton() {
        System.out.println("Singleton Constructor Called!");
    }

    public static ThreadSafeLockingSingleton getInstance() {
        synchronized (ThreadSafeLockingSingleton.class) { // Lock for thread safety
            if (instance == null) {
                instance = new ThreadSafeLockingSingleton();
            }
            return instance;
        }
    }

    public static void main(String[] args) {
        ThreadSafeLockingSingleton s1 = ThreadSafeLockingSingleton.getInstance();
        ThreadSafeLockingSingleton s2 = ThreadSafeLockingSingleton.getInstance();

        System.out.println(s1 == s2);
    }
}

// maanlete 2 alag alag system ne ek hi baar ek hi time pe exact Singleton::getInstance(); call kiya us time ke liye

// mutex is used to ensure that only one thread can access the getInstance() method at a time,
// preventing multiple instances from being created in a multi-threaded environment.
//----Matlab ek time me ek thread ko getInstance() method access karne dega,
//----jab tak ki us thread ka kaam complete nahi ho jata, tab tak dusre thread ko wait karna padega.
// lock_guard is a C++ RAII wrapper for mutexes that automatically releases the lock when it goes out of scope.



// Note: This implementation can lead to performance issues due to locking every time getInstance() is called.