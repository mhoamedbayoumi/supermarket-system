#include<string>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
using namespace std;
class products
{
private:
    int product_number;
    string product_name;
    float product_price,product_qty;
    float discounts,taxes;
public:
    void create_product()
    {
        cout<<"enter the product number \n";
        cin>>product_number;
        cout<<"enter the product name \n";
        cin>>product_name;
        cout<<"enter the product price \n";
        cin>>product_price;
        cout<<"enter the product quantity \n";
        cin>>product_qty;
        cout<<"enter the product discount \n";
        cin>>discounts;
        cout<<"enter the product taxes \n";
        cin>>taxes;
    }
    void show_info()
    {
        cout<<"the product number is "<<product_number<<endl;
        cout<<"the product name is "<<product_name<<endl;
        cout<<"the product price is "<<product_price<<endl;
        cout<<"the product quantity is "<<product_qty<<endl;
        cout<<"the product discount is "<<discounts<<endl;
        cout<<"the product taxes is "<<taxes<<endl;
    }
    int product_numbers()
    {
        return product_number;
    }
    string product_names()
    {
        return product_name;
    }
    float product_prices()
    {
        return product_price;
    }
    float product_qtys()
    {
        return product_qty;
    }
    float discountss()
    {
        return discounts;
    }
    float taxess()
    {
        return taxes;
    }

};
products product_one;
fstream my_file;
void write_product()
{
    my_file.open("supermarket.txt",ios::out|ios::app);
    product_one.create_product();
    my_file.write((char*)&product_one,sizeof(products));
    my_file.close();
    cout<<"\n the product has created "<<endl;
    getchar();
}
void display_product()
{
    cout<<"all the products information \n \n";
    my_file.open("supermarket.txt",ios::in);
    while(my_file.read((char*)&product_one,sizeof(products)))
    {
        product_one.show_info();
        cout<<"\n \n ################################# \n \n ";
        getchar();
    }
    my_file.close();
    getchar();

}
void search_products(int num)
{
    int flag=0;
    my_file.open("supermarket.txt",ios::in);
    while(my_file.read((char*)&product_one,sizeof(products)))
    {
        if(product_one.product_numbers()==num)
        {
            product_one.show_info();
            flag=1;
        }
    }
    my_file.close();
    if(flag==0)
    {
        cout<<"product not found \n \n ";
        getchar();
    }
}
void delete_products()
{
    int num;
    cout<<"please enter the product you want to delete \n";
    cin>>num;
    my_file.open("supermarket.txt",ios::in|ios::out);
    fstream my_file2;
    my_file2.open("replace.txt",ios::out);
    my_file.seekg(0,ios::beg);
    while(my_file.read((char*)&product_one,sizeof(products)))
    {
        if(product_one.product_numbers()!=num)
        {
            my_file2.write((char*)&product_one,sizeof(products));
        }
    }
    my_file2.close();
    my_file.close();
    remove("supermarket.txt");
    cout<<"the product deleted \n ";
    getchar();
}
int main()
{
    char ch;
    cout<<"\n Main menu! \n";
    cout<<"\n 1- create product :\n";
    cout<<"\n 2- display all products :\n";
    cout<<"\n 3 -search product :\n";
    cout<<"\n 4 - Delete product :\n";
    cout<<"\n 5-view product menu :\n";
    cout<<"\n 6- Exit :\n";
    cout<<"\n please enter your choice 1-6 :\n";
    int choice;
    cin>>choice;
    do{
    switch(choice)
    {
    case 1:
        write_product();
        break;
    case 2:
        display_product();
        break;
    case 3:
        int num;
        cout<<"enter the number to search \n";
        cin>>num;
        search_products(num);
        break;
    case 4:
        delete_products();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout<<"eror\n";
        exit(0);

    }
    }while(ch!=5);
    return 0;
}

