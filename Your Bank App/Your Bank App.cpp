#include <iostream>
#include <cctype>
#include <map>          

using namespace std;

int main() {
    int choice;
    string firstName, secondName, nationalId, passWord, confirmPass;

    map<string, string> accounts;  //string عشان هنعمل ربط بين كلمة السر و الرقم القومي و الاننين عبارة عن 
    map<string, long long> balances;  //long longو هنا بردو بس هنا ربط الرصيد ب الرقم القومي و الرصيد نوعه   

    while (true) {


        while (true) {
        
            cout << endl;
            cout << "  *********************************************\n";
            cout << "  *                                            *\n";
            cout << "  *        ^ WELCOME TO YOUR BANK APP ^        *\n";
            cout << "  *                                            *\n";
            cout << "  **********************************************\n";
            cout << "  *                                            *\n";        
            cout << "  *   [1] Create Account                       *\n";
            cout << "  *   [2] Login                                *\n";
            cout << "  *   [3] Delete Account                       *\n";
            cout << "  *                                            *\n";
            cout << "  *                                            *\n";
            cout << "  *                                            *\n";
            cout << "  **********************************************\n";

            do {
                cout << " >> Please enter your choice: ";
                cin >> choice;
                cout << endl;
            } while (choice < 1 || choice > 3);

            // إدخال الاسم الأول والتحقق منه
            if (choice == 1) {
                while (true) {
                    cout << " >> Enter Your First Name: ";
                    cin >> firstName;
                    cout << endl;
                    bool isValid = true;                  //نفرض ان الاسم صحيح
                    for (char c : firstName) {           //التكرار على كل حرف في الاسم
                        if (!isalpha(c)) {               // لو كان الحرف مش أبجدي
                            isValid = false;              // الاسم غير صحيح
                            break;
                        }
                    }

                    if (isValid) break;              //هنا لو الاسم صح هيقبل الاسم و يخرج برا اللوب
                   
                    else cout << " >>User name doesn't match the description required.\nPlease try again!\n";
                }                                                    //و هنا عشان يطبع رسالة التحذير لو الاسم غلط 
              
                                                                     // إدخال الاسم الثاني والتحقق منه
                while (true) {
                    cout << " >> Enter Your Second Name: ";
                    cin >> secondName;
                    cout << endl;
                    bool isValid = true;
                    for (char c : secondName) {                 // هنا زي م حصل ف الاسم الاول
                        if (!isalpha(c)) {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) break;
                    else cout << " >> User name doesn't match the description required.\nPlease try again!\n";
                }
                //=============================================================================================================================

                cout << " >> Enter valid National ID: ";
                cin >> nationalId;
                cout << endl;                          //لو الرقم القومي مش 14 رقم هيفضل يكرر ف الكرر في اللوب لحد م يدخل 14 رقم
                while (nationalId.length() != 14) {                  
                    cout << " >> Invalid National ID. It should be 14 digits and contain only numbers.\n  Please try again !\n" << endl;
                    cout << " >> Enter valid National ID: ";
                    cin >> nationalId;
                    cout << endl;
                }

                              // اللوب دي عشان نعمل فحص عشان لو المستخدم دخل اي حرف او اي حاجة غير الارقام
                while (true) {
                    bool isValid = true;                                   //نفرض ان الرقم القومي صحيح
                    for (char c : nationalId) {                          //عشان يعدي على كل حرف و يشوفه رقم ولا
                        if (!isdigit(c)) {
                            isValid = false;        //هنا الرقم القومي غلط عشان المستخدم دخل حاجة غير الارقام
                            break;
                        }
                    }

                    if (isValid) {
                        break;                                     // لو كل الأرقام صحيحة نخرج من اللوب                         
                    }
                    else {
                        cout << " >> Invalid National ID. It should contain only numbers." << endl;
                        cout << " >> Enter valid National ID: ";
                        cin >> nationalId;
                        cout << endl;
                    }
                }
                //==================================================================================================================
                do {
                    cout << " >> Enter Your Password (6-12 characters): "; //احنا هنا عاميلين شرط لكلمة السر ان يكون من6الى 12 ديجيت
                    cin >> passWord;
                    cout << endl;
                    cout << " >> Confirm password: ";
                    cin >> confirmPass;                                      // تاكيد لكلمة السر
                    if (passWord != confirmPass || passWord.length() > 12 || passWord.length() < 6) {
                        cout << " >> Password doesn't match the description required.\nPlease try again!\n";
                    }
                } while (passWord != confirmPass || passWord.length() > 12 || passWord.length() < 6);
               
                accounts[nationalId] = passWord;        //map ربط كلمة السر بالرقم القومي و حفظها في 
                balances[nationalId] = 0;               //وهنا بردو بس مع الرصيد اللي ف الحساب
                cout << "\n Signed Up Successfully!\n";
            }
           
            //=============================================================================================================================

            else if (choice == 2) {              // Log In الشرط ده لو المستخدم عمل 
                cout << " >> Enter Your National ID: ";
                cin >> nationalId;

                if (accounts.find(nationalId) == accounts.end()) {       // الشرط ده عشان يشوف الرقم القومي متسجل اصلا ولا لأ 
                    cout << " >> This National ID is not registered. Please sign up first.\n";
                    continue;           //بيعمل اسكيب للبعده و يرجع من الاول خالص عشان الرقم القومي مش متسجل 
                }

                cout << " >> Enter Your Password: ";
                cin >> passWord;
                if (accounts[nationalId] != passWord) {     // الشرط هنا بيتأكد ان كلمة السر زي اللي اتعملت اثتاء التسجيل ولا لأ
                    cout << " >> Invalid password. Returning to main menu.\n";
                    continue;                      //بيعمل اسكيب للبعده و يرجع من الاول خالص عشان كلمة السر غلط 
                }
            }
          
            //===================================================================================================================================
          
            else if (choice == 3) {        // Delete Account الشرط ده لو المستخدم اختار 
                cout << " >> Enter Your National ID to delete account: ";
                cin >> nationalId;

                if (accounts.find(nationalId) == accounts.end()) {  // بنشوف الاول هو موجود اصلا ولا لأ اصل مش هيعمل حذف لحاجة مش موجودة يعني هههههه
                    cout << " >> This National ID is not registered.\n";
                    continue;                            
                }

                cout << " >> Enter Your Password to confirm deletion: "; 
                cin >> passWord;
                                                                  //بنطلب منه يدخل كلمة السر و نفحصها ف الشرط اللي جااي
                if (accounts[nationalId] == passWord) {  
                    accounts.erase(nationalId);       // map حذف الحساب من على ال 
                    balances.erase(nationalId);       // و الرصيد بردو م هو دخول الحمام مش زي خروجه يعني هناخد فلوسك قبل م تمشي هههههه  

                    cout << "Account deleted successfully!\n";
                }
                else {
                    cout << " >> Incorrect password. Account deletion canceled.\n";
                }
                continue;
            }

            if (choice == 2) { break; }      // كان بيرجع من الاول خالص و انا مش عايز كده انا عايزه يدخل على اللى بعده Log Inدي عملتها عشان لما مان بيختار 
        }
       
                         //  😂  اخيارا خلصنا المرحلة الاولى و اللي هي التسجيل و الدخول ندخل بقا ف الفلوس بقاااااااا

        
        //##############################################################################################################################################################################################################################33
        cout<< endl;
        cout << "  *********************************************\n";
        cout << "  *                                            *\n";
        cout << "  *   [1] Withdraw Money                       *\n";
        cout << "  *   [2] Deposit Money                        *\n";
        cout << "  *   [3] Check Account Balance                *\n";
        cout << "  *   [4] Exit                                 *\n";
        cout << "  *                                            *\n";
        cout << "  *********************************************\n";
      
        int choice2;
        long long amount, deposit;

        while (true) {
            cout << "\n >> Enter valid choice: ";
            cin >> choice2;

            if (choice2 == 1) {
                cout << "\n >> Enter the amount you want to withdraw : ";
                cin >> amount;
                if (amount > balances[nationalId] || amount == 0) {  // بنشوف الرصيد اللي في الحساب هيكفي المبلغ اللي عايز يسحبه ولا لأ
                    cout << "\n >> Your balance is insufficient!\n";
                }
                else {
                    cout << "\n\n Amount Withdrawn Successfully!\n";
                    balances[nationalId] -= amount;                // بنطرح البلغ المسحوب من الرصيد
                }
            }
           
            //==================================================================================
           
            else if (choice2 == 2) {
                cout << "\n >> Enter the amount you want to deposit (10$:100000$) : ";      //عشان احنا بنك منظم ف عاملين حدود للمبلغ اللي هتعمله ايداع      
                cin >> deposit;
                if (deposit >= 10 && deposit <= 100000) {                       // عشان نتأكد بس ان المستخدم سمع الكلام
                    balances[nationalId] += deposit;                                 // بنضيف المبلغ اللي اتعمله ايداع على الرصيد 
                    cout << "\nDeposit has been done successfully!\n";
                }
                else {
                    cout << "\n >> Please enter an amount within the specified range.\n";    //دا لو المستخدم طلع مش بيشوف و حط مبلغ غير اللي قولنا عليه
                }
            }
          
            //=====================================================================================
          
            else if (choice2 == 3) {
                cout << "\n >> Your balance is: " << balances[nationalId] << "\n";            // الاستعلام بقا عشان الثقة و كده 
            }
          
            //=====================================================================================
           
            else if (choice2 == 4) {                                              // خلاص كده انت خلصت يابا ؟ اخرج بقاااا تعبتنا معااااااك 
                cout << "\n Exiting... Thank you for using our Bank App!\n";
                break;
            }
        }
    }
    return 0;
    }



                                                                                                                                                                                                  /*                                             
                                                                       *****   *****  
                                                                     *****************  
                                                                    *******************  
                                                                    *******************  
                                                                     *****************  
                                                                       *************  
                                                                         *********  
                                                                           *****  
                                                                             *  
                                                                                                               
                                             >>>>>>>>>>>>>>>>>>>>>>❤❤❤❤❤❤❤❤❤❤❤❤<<<<<<<<<<<<<<<<<<<<<<<      
                                                                                                            
                                                                       ^  THANK YOU ^ ❤ ☺                                       
                                                                                                            
                                             >>>>>>>>>>>>>>>>>>>>>>❤❤❤❤❤❤❤❤❤❤❤❤<<<<<<<<<<<<<<<<<<<<<<<<      
                                                                                               
                                                                                                                                                               
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
 =======================================================         >>    ^ THE END ^ 💻👋     <<       ================================================================                                                                                                                                         
                                                                                                                                          
                                                                                                                                          
                                                                                                                                          
                                                                                                                                          
                                                                                                                                          
                                                                                                                                          
                                                                                                                                                                                                 */




