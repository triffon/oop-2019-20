

int main()
{

    List l;
    for (List::Iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it;
    }
    return 0;
}