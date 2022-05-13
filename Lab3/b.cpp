//#include <thread>
//#include <mutex>
//#include <iostream>
//#include <atomic>
////
//#define mb() 	asm volatile("mfence" : : : "memory")
//
////#define mb()
//static volatile std::atomic<int> orangeNum(0);
//static volatile std::atomic<int> appleNum(0);
//static volatile constexpr int FULL = 1;
//static volatile constexpr int EMPTY = 0;
//
//class spin_lock
//{
//    static constexpr int UNLOCKED = 1;
//
//    static constexpr int LOCKED = 0;
//
//    std::atomic<int> m_value{1};
//
//public:
//    void lock_and_op(int opcode)
//    {
//        while (true)
//        {
//            int expected = UNLOCKED;
//            if (m_value.compare_exchange_strong(expected, LOCKED))
//                break;
//        }
//        switch (opcode) {
//            case 1:
//
//        }
//    }
//
//    void unlock()
//    {
//        m_value.store(UNLOCKED);
//    }
//};
//
//
//
//
//
//static spin_lock myLock;
//
//void * mom(void * arg){
//    int expect = EMPTY;
//    while(true){
//        if (appleNum == EMPTY && orangeNum == EMPTY){
//            mb();
//            myLock.lock();
//            std::cout<<"plate trying locked by mom"<<std::endl;
//            mb();
//            if (appleNum.compare_exchange_strong(expect,EMPTY) && orangeNum.compare_exchange_strong(expect,FULL)){
//                std::cout<<"plate locked by mom, successfully"<<std::endl;
//                std::cout<<"mom put orange."<<std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                std::cout<<"plate unlocked by mom"<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//            else {
//                std::cout << "plate failed locked by mom,return lock " << std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//        } else {
//            std::cout << "mom cannot put orange.There is something in it" << std::endl;
//            std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//            mb();
//            myLock.unlock();
//            continue;
//        }
//    }
//}
//
//void * dad(void * arg){
//    int expect = EMPTY;
//
//    while(true){
//        if (appleNum == EMPTY && orangeNum == EMPTY){
//            mb();
//            myLock.lock();
//            std::cout<<"plate trying locked by dad"<<std::endl;
//            mb();
//            if (appleNum.compare_exchange_strong(expect,FULL) && orangeNum.compare_exchange_strong(expect,EMPTY)){
//                std::cout<<"plate locked by dad, successfully"<<std::endl;
//                std::cout<<"dad put apple."<<std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                std::cout<<"plate unlocked by dad"<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//            else {
//                std::cout << "plate failed locked by dad,returning lock " << std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//        } else {
//            std::cout << "dad cannot put orange.There is something in it" << std::endl;
//            std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//            mb();
//            myLock.unlock();
//            continue;
//        }
//    }
//}
//
//void * son(void * arg) {
//    int FULLexpect = FULL;
//    int EMPTYexpect = EMPTY;
//    while(true){
//        if (appleNum == EMPTY && orangeNum == FULL){
//            mb();
//            myLock.lock();
//            std::cout<<"plate trying locked by son"<<std::endl;
//            mb();
//            if (appleNum.compare_exchange_strong(EMPTYexpect,FULL) && orangeNum.compare_exchange_strong(FULLexpect,EMPTY)){
//                std::cout<<"plate locked by son, successfully"<<std::endl;
//                std::cout<<"son take out orange."<<std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                std::cout<<"plate unlocked by son"<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//            else {
//                std::cout << "plate failed locked by son,returning lock " << std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//        } else {
//            std::cout << "son cannot take out orange." << std::endl;
//            std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//            mb();
//            myLock.unlock();
//            continue;
//        }
//    }
//}
//
//
//void * daughter(void * arg) {
//    int FULLexpect = FULL;
//    int EMPTYexpect = EMPTY;
//
//    while(true){
//        if (appleNum == FULL && orangeNum == EMPTY){
//            mb();
//            myLock.lock();
//            std::cout<<"plate trying locked by daughter"<<std::endl;
//            mb();
//            if (appleNum.compare_exchange_strong(FULLexpect,EMPTY) && orangeNum.compare_exchange_strong(EMPTYexpect,EMPTY)){
//                std::cout<<"plate locked by daughter, successfully"<<std::endl;
//                std::cout<<"daughter take out apple."<<std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                std::cout<<"plate unlocked by daughter"<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//            else {
//                std::cout << "plate failed locked by daughter,returning lock " << std::endl;
//                std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//                mb();
//                myLock.unlock();
//                continue;
//            }
//        } else {
//            std::cout << "daughter cannot take out apple." << std::endl;
//            std::cout<<"orangeNum:"<<orangeNum<<", apple:"<<appleNum<<std::endl;
//            mb();
//            myLock.unlock();
//            continue;
//        }
//    }
//}
//
//
//int main(){
//    pthread_t monThread, dadThread, sonThread, daughterThread;
//    int ret;
//    pthread_create(&monThread, nullptr, mom, 0);
//    pthread_create(&dadThread,nullptr, dad,0);
//    pthread_create(&sonThread,nullptr, son,0);
//    pthread_create(&daughterThread,nullptr, daughter,0);
//
//
//    pthread_join(monThread,NULL);
//    pthread_join(dadThread,NULL);
//    pthread_join(sonThread,NULL);
//    pthread_join(daughterThread,NULL);
//
//}