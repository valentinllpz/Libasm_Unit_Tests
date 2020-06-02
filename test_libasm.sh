touch tmp{1..5}
echo "For, after all, how do we know that two and two make four? Or that the force of gravity works? Or that the past is unchangeable? If both the past and the external world exist only in the mind, and if the mind itself is controllable – what then?" >> tmp6
make
clear
printf "\e[1;35m"
printf "#******************************************************************************#\n"
printf "#                                                                              #\n"
printf "#                   :::          :::                                           #\n"
printf "#                  :+:      :+: :+:                                            #\n"
printf "#                 +:+          +:+                                             #\n"
printf "#                +#+      +#+ +#+#+#+  +#+#+#+  +#+#+#+ +#+#+#+#+              #\n"
printf "#               #+#      #+# #+#  #+#     +#+# #+#+    #+#  +  #+#             #\n"
printf "#              #+#      #+# #+#  #+# #+#  #+#    +#+# +#+  +  #+#              #\n"
printf "#             ######## ### #######   ####### ####### ###  #  ###               #\n"
printf "#                                                                              #\n"
printf "#                                            Basic unit tests                  #\n"
printf "#                                                                              #\n"
printf "#******************************************************************************#\n\n"
printf "\e[0m"

PS3='Welcome to this Libasm tester! Please enter your choice: '
options=("Test all" "Test ft_strlen" "Test ft_strcpy" "Test ft_strcmp" "Test ft_write" "Test ft_read" "Test ft_strdup" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Test all")
            echo "Testing all..."
			gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "0"
            break
            ;;
        "Test ft_strlen")
            echo "Testing only ft_strlen..."
            gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "1"
            ;;
        "Test ft_strcpy")
            echo "Testing only ft_strcpy..."
            gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "2"
            ;;
        "Test ft_strcmp")
            echo "Testing only ft_strcmp..."
            gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "3"
            ;;
        "Test ft_write")
            echo "Testing only ft_write..."
            gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "4"
            ;;
        "Test ft_read")
            echo "Testing only ft_read..."
            gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "5"
            ;;
        "Test ft_strdup")
            echo "Testing only ft_strdup..."
            gcc -Wall -Wextra -Werror main.c -L . -lasm && ./a.out "6"
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
rm tmp*
make clean