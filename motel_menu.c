#include <stdio.h>

int main()
{
    int main_choice, item;
    char op;

    int price[20] = {
        0,
        10, 15, 40, 40, 60, 40, 30, 25,   // Breakfast
        120, 80, 15, 30,                 // Lunch/Dinner
        20, 20, 20                       // Beverages
    };

    int qty[20] = {0};

    printf("\n========================================\n");
    printf("        WELCOME TO THE MOTEL\n");
    printf("           🟢 VEG ONLY 🟢\n");
    printf("        Hungry? We're Ready!\n");
    printf("========================================\n");

    while (1)
    {
        printf("\nMAIN MENU (VEG ONLY)\n");
        printf("1.Breakfast 🍽️\n");
        printf("2.Lunch / Dinner 🥣\n");
        printf("3.Hot Beverages ☕\n");
        printf("4.Exit 😋\n");
        printf("Enter choice: ");
        scanf("%d", &main_choice);

        if (main_choice == 1)
        {
            while (1)
            {
                printf("\n--- BREAKFAST MENU ---\n");
                printf("1.Idly 2.Vada 3.Masala Dosa 4.Set Dosa\n");
                printf("5.Chole Bature 6.Pulao 7.Bisi Bele Bath 8.Curd Rice\n");
                printf("9.Back\n");
                scanf("%d", &item);

                if (item == 9) break;
                if (item < 1 || item > 8) continue;

                printf("Press + to ADD, - to REMOVE, q to quit item\n");
                while (1)
                {
                    scanf(" %c", &op);
                    if (op == 'q') break;

                    if (op == '+') qty[item]++;
                    else if (op == '-' && qty[item] > 0) qty[item]--;

                    printf("Price: Rs.%d | Qty: %d | Amount: Rs.%d\n",
                           price[item], qty[item], qty[item] * price[item]);
                }
            }
        }

        else if (main_choice == 2)
        {
            while (1)
            {
                printf("\n--- LUNCH / DINNER ---\n");
                printf("1.Full Meals 2.Half Meals 3.Ragi Ball 4.Sambar Sadam\n");
                printf("5.Back\n");
                scanf("%d", &item);

                if (item == 5) break;
                if (item < 1 || item > 4) continue;

                item += 8;

                printf("Press + to ADD, - to REMOVE, q to quit item\n");
                while (1)
                {
                    scanf(" %c", &op);
                    if (op == 'q') break;

                    if (op == '+') qty[item]++;
                    else if (op == '-' && qty[item] > 0) qty[item]--;

                    printf("Price: Rs.%d | Qty: %d | Amount: Rs.%d\n",
                           price[item], qty[item], qty[item] * price[item]);
                }
            }
        }

        else if (main_choice == 3)
        {
            while (1)
            {
                printf("\n--- HOT BEVERAGES ---\n");
                printf("1.Coffee 2.Tea 3.Badam Milk\n");
                printf("4.Back\n");
                scanf("%d", &item);

                if (item == 4) break;
                if (item < 1 || item > 3) continue;

                item += 12;

                printf("Press + to ADD, - to REMOVE, q to quit item\n");
                while (1)
                {
                    scanf(" %c", &op);
                    if (op == 'q') break;

                    if (op == '+') qty[item]++;
                    else if (op == '-' && qty[item] > 0) qty[item]--;

                    printf("Price: Rs.%d | Qty: %d | Amount: Rs.%d\n",
                           price[item], qty[item], qty[item] * price[item]);
                }
            }
        }

        else if (main_choice == 4)
        {
            break;   // EXIT
        }
    }

    /* -------- BILL ONLY IF ORDER EXISTS -------- */
    int total = 0;
    for (int i = 1; i <= 15; i++)
        total += qty[i] * price[i];

    if (total > 0)
    {
        printf("\n---------- FINAL BILL ----------\n");
        printf("Subtotal : Rs.%d\n", total);
        printf("GST 5%%    : Rs.%d\n", total * 5 / 100);
        printf("Total     : Rs.%d\n", total + (total * 5 / 100));
        printf("--------------------------------\n");
    }

    printf("🟢 VEG ONLY | Hungry? We're Ready!😋\n");
    printf("Thank You! Visit Again 😊\n");

    return 0;
}
