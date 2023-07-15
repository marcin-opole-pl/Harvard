 if (argc != 2)
    {
        printf("One argument needed \n");
        return 1;
    }
    // Check if argument has 26 letters
    if (strlen(argv[1]) != 26)
    {
        printf("26 letters required \n");
        return 1;
    }
    // Check if any chars are nonalphabetic
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Only letters accepted \n");
            return 1;
        }
    }
    // Check if no two similars letters
    for (int i = 0; i < (strlen(argv[1]) - 1); i++)
    {
        if (tolower(argv[1][i]) == tolower(argv[1][i+1]))
        {
            printf("No similar letters \n");
            return 1;
        }
    }