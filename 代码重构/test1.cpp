//修改前
int discount(int inputVal ,int quantity, int yearToDate)
{
    if(inputVal > 50) inputVal -= 2;
    if(quantity > 50) inputVal -= 2;
    if(yearToDate > 50) inputVal -= 2;

    return inputVal;
}

//修改后
int discount(int inputVal ,int quantity, int yearToDate)
{
    int result = inputVal;
    if(inputVal > 50) result -= 2;
    if(quantity > 50) result -= 2;
    if(yearToDate > 50) result -= 2;

    return result;
}
