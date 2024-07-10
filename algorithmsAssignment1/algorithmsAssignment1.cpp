

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

class Product 
{
public:
    int id;
    string name;
    float price;
    string category;
    Product(int i, string n, float p, string c) 
    {
        id = i;
        name = n;
        price = p;
        category = c;
    }
    Product() {
        id = 0;
        name = "";
        price = 0;
        category = "";
    }
};
class LinkedList {
private:

    typedef struct node
    {
        Product data;
        node* next;
    }* ptr;

    ptr head;
    ptr curr;
    ptr temp;

public:
    LinkedList() 
    {
        head = NULL;
        curr = NULL;
        temp = NULL;
    };
    void AddNode(Product addData) 
    {
        ptr n = new node;
        n->next = NULL;
        n->data = addData;

        if (head != NULL) 
        {
            curr = head;
            while (curr->next != NULL) 
            {
                curr = curr->next;
            }
            curr->next = n;
        }
        else 
        {
            head = n;
        }
    };
    void DeleteNode(int delData)
    {
        ptr delPtr = NULL;
        temp = head;
        curr = head;

            while (curr != NULL && curr->data.id != delData)
            {
                temp = curr;
                curr = curr->next;
            }
            if (curr == NULL) 
            {
                cout << "\n" << delData << " WAS NOT A VALID ID IN THE LIST!\n";
                delete delPtr;
            }
            else 
            {
                delPtr = curr;
                curr = curr->next;
                temp->next = curr;
                delete delPtr;
                cout << "\n THE PRODUCT WITH THE ID '" << delData << "' WAS ELIMINATED WITH NO TRACE!\n";
            }
    };
    void DeleteNode(string delName)
    {
        ptr delPtr = NULL;
        temp = head;
        curr = head;

            while (curr != NULL && curr->data.name != delName)
            {
                temp = curr;
                curr = curr->next;
            }
            if (curr == NULL)
            {
                cout << "\n"<< delName << " WAS NOT A VALID NAME IN THE LIST!";
                delete delPtr;
            }
            else
            {
                delPtr = curr;
                curr = curr->next;
                temp->next = curr;
                delete delPtr;
                cout << "\n THE PRODUCT WITH THE NAME '" << delName << "' WAS ELIMINATED WITH NO TRACE!\n";
            }
    };

    void EditNode(int searchData)
    {
        temp = head;
        curr = head;
            while (curr != NULL && curr->data.id != searchData)
            {
                temp = curr;
                curr = curr->next;
            }
            if (curr == NULL)
            {
                cout <<"\n"<< searchData << " WAS NOT A VALID ID IN THE LIST!";
            }
            else {
                char choice = 0;
                while (choice != 5) {
                    cout << "\nProduct Found! What piece of data would you like to change?\n1. ID\n2. NAME\n3. PRICE\n4. CATEGORY\n5. FINISHED EDITING\n";

                    cin >> choice;
                    switch (choice) {
                    case '1':
                    {
                        cout << "This product's current id is: " << curr->data.id << " What would you like to change it to?";
                        string newData;
                        cin >> newData;
                        curr->data.id = stoi(newData);
                        cout << "This product's id is now: " << curr->data.id;
                        break;
                    }
                    case '2':
                    {
                        cout << "This product's current name is: " << curr->data.name << " What would you like to change it to?";
                        string newData;
                        cin.ignore();
                        getline(cin, newData);
                        curr->data.name = newData;
                        cout << "This product's name is now: " << curr->data.name;
                        break;
                    }
                    case '3':
                    {
                        cout << "This product's current price is: " << curr->data.price << " What would you like to change it to?";
                        string newData;
                        cin >> newData;
                        curr->data.price = stof(newData);
                        cout << "This product's price is now: " << curr->data.price;
                        break;
                    }
                    case '4':
                    {
                        cout << "This product's current category is: " << curr->data.category << " What would you like to change it to?";
                        string newData;
                        cin.ignore();
                        getline(cin, newData);
                        curr->data.category = newData;
                        cout << "This product's name is now: " << curr->data.category;
                        break;
                    }
                    case '5':
                    {
                        cout << "\nFinished editing great job!\n";
                        return;
                    }
                    default: 
                        cout << "\nBad Input... youve given a bad bad input... you deserved to be punished....\n";
                        break;
                    }
                }
            }
    };
    void EditNode(string searchData)
    {
        temp = head;
        curr = head;
        while (curr != NULL && curr->data.name != searchData)
        {
            temp = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "\n" << searchData << " WAS NOT A VALID NAME IN THE LIST!";
        }
        else {
            char choice = 0;
            while (choice != 5) {
                cout << "\nProduct Found! What piece of data would you like to change?\n1. ID\n2. NAME\n3. PRICE\n4. CATEGORY\n5. FINISHED EDITING\n";

                cin >> choice;
                switch (choice) {
                case '1':
                {
                    cout << "This product's current id is: " << curr->data.id << " What would you like to change it to?";
                    string newData;
                    cin >> newData;
                    curr->data.id = stoi(newData);
                    cout << "This product's id is now: " << curr->data.id;
                    break;
                }
                case '2':
                {
                    cout << "This product's current name is: " << curr->data.name << " What would you like to change it to?";
                    string newData;
                    cin.ignore();
                    getline(cin, newData);
                    curr->data.name = newData;
                    cout << "This product's name is now: " << curr->data.name;
                    break;
                }
                case '3':
                {
                    cout << "This product's current price is: " << curr->data.price << " What would you like to change it to?";
                    string newData;
                    cin >> newData;
                    curr->data.price = stof(newData);
                    cout << "This product's price is now: " << curr->data.price;
                    break;
                }
                case '4':
                {
                    cout << "This product's current category is: " << curr->data.category << " What would you like to change it to?";
                    string newData;
                    cin.ignore();
                    getline(cin, newData);
                    curr->data.category = newData;
                    cout << "This product's name is now: " << curr->data.category;
                    break;
                }
                case '5':
                {
                    cout << "\nFinished editing great job!\n";
                    return;
                }
                default:
                    cout << "\nBad Input... youve given a bad bad input... you deserved to be punished....\n";
                    break;
                }
            }
        }
    };
    void FindNode(int searchData) {
        temp = head;
        curr = head;
            while (curr != NULL && curr->data.id != searchData)
            {
                temp = curr;
                curr = curr->next;
            }
            if (curr == NULL)
            {
                cout << "\n" << searchData << " WAS NOT A VALID ID IN THE LIST!";
            }
            else {
                cout << "\nThe product with the id: " << searchData << " has the following properties:\nName: " << curr->data.name << "\nPrice: " << curr->data.price << "\nCategory: " << curr->data.category<<"\n";
            }

    }
    void FindNode(string searchData) {
        temp = head;
        curr = head;

        while (curr != NULL && curr->data.name != searchData)
        {
            temp = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "\n" << searchData << " WAS NOT A VALID NAME IN THE LIST!";
        }
        else {
            cout << "\nThe product with the name: " << searchData << " has the following properties:\ID: " << curr->data.id << "\nPrice: " << curr->data.price << "\nCategory: " << curr->data.category << "\n";
        }

    }
    void BubbleBobbleSortForever() 
    {
        int totalSwaps = 0;
        int runs = 0;
        bool swapped;
        do {
            runs++;
            swapped = false;
            curr = head;
            while (curr != NULL && curr->next != NULL)
            {
                if (curr->data.price > curr->next->data.price)
                {
                    
                    Product temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    totalSwaps++;
                    swapped = true;  
                }
                curr = curr->next;
            }
        } while (swapped);
        cout << "\nCONGRATULATIONS YOUR PRODUCTS HAVE BEEN SORTED BY PRICE USING BUBBLE SORT. THIS TOOK A TOTAL OF " << totalSwaps << " SWAPS IN "<< runs <<" RUN THROUGHS. GO AHEAD AND TAKE A LOOK AT YOUR SORTED DATA FROM THE MENU.\n";
    }
    void PrintList() {
        curr = head;
        while (curr != NULL) {
            cout << curr->data.id << ", " << curr->data.name << ", " << curr->data.price << ", " << curr->data.category << "\n";
            curr = curr->next;
        }
    };


};




int main()
{
    Product sample(0, "sample", 0.1, "test");

    //list<int> id = {};
   // list<string> name = {};
   // list<float> price = {};
   // list<string> category = {};
    LinkedList products = LinkedList();

    cout << "Hello World!\n";
    ifstream productData;
    productData.open("product_data.txt");
    string tempId;
    string tempName;
    string tempPrice;
    string tempCat;
    int lineCount = 0;

    while (productData.peek() != -1)
    {
        

        getline(productData, tempId, ',');

        cout << tempId + ", ";

        productData >> ws;
        getline(productData, tempName, ',');

        cout << tempName + ", ";

        productData >> ws;
        getline(productData, tempPrice, ',');

        cout << tempPrice + ", ";

        productData >> ws;
        getline(productData, tempCat);

        cout << tempCat + "\n";
        Product p = Product(stoi(tempId), tempName, stof(tempPrice), tempCat);
        products.AddNode(p);


    }
    int optionselect = 0;
    string placehold;
    while (true) 
    {
        cout << "\nYour options are as follows!\n1. Insert new product\n2. Update a product's details\n3. Delete a product\n4. Search for a product\n5. View all products\n6. Bubble sort ACTIVATE!\n";
        cin >> optionselect;

        if (optionselect == 1)
        {
            cout << "\nPlease insert product id: ";
            cin >> tempId;
           // id.push_back(stoi(word1));
            cin.ignore();
            cout << "\nPlease insert product name: ";
            getline(cin, tempName);
          //  name.push_back(word1);

            cout << "\nPlease insert product price: ";
            cin >> tempPrice;
           // price.push_back(stof(word1));
            cin.ignore();
            cout << "\nPlease insert product category: ";
            getline(cin, tempCat);
          //  category.push_back(word1);

                Product q = Product(stoi(tempId), tempName, stof(tempPrice), tempCat);
                products.AddNode(q);
            
            //cout << "\nThe new product added has the following attributes:\n" + to_string(id.back())+ ", " + name.back() + ", " + to_string(price.back()) + ", " + category.back();
        }
        else if (optionselect == 2) 
        {
            cout << "\nSelect the product based on:\n1. ID\n2. Name\n";
            cin >> optionselect;
            if (optionselect == 1) 
            {
                cout << "\nPlease insert product id: ";
                cin >> placehold;
                products.EditNode(stoi(placehold));
            }
            else if (optionselect == 2) {
                cin.ignore();
                cout << "\nPlease insert product name: ";
                getline(cin, placehold);
                products.EditNode(placehold);
            }
        }
        else if (optionselect== 3) 
        {
            
            cout << "\nWould you like to find the product based on:\n1. Id\n2. Name\n";
            cin >> optionselect;
            if (optionselect == 1) {
                cout << "\nThank you for your punctual response! Please now enter the ID: ";
                cin >> placehold;
                products.DeleteNode(stoi(placehold));
                
            }
            else if (optionselect == 2) {
                cin.ignore();
                cout << "\nThank you for your punctual response! Please now enter the name: ";
                getline(cin, placehold);
                products.DeleteNode(placehold);
            }
        }
        else if (optionselect == 4) {
            cout << "\nWould you like to find the product based on:\n1. Id\n2. Name\n";
            cin >> optionselect;
            if (optionselect == 1) {
                cout << "\nThank you for your punctual response! Please now enter the ID: ";
                cin >> placehold;
                products.FindNode(stoi(placehold));

            }
            else if (optionselect == 2) {
                cin.ignore();
                cout << "\nThank you for your punctual response! Please now enter the name: ";
                getline(cin, placehold);
                products.FindNode(placehold);
            }
        }
        else if (optionselect == 5) {
            products.PrintList();
        }
        else if (optionselect == 6) {
            products.BubbleBobbleSortForever();
        }
    }

}
