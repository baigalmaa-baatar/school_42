gcc -Wall -Werror -Wextra inter.c -o inter
echo "# Expected result (next line) Your result #"
echo "---"
echo "padinto$"
./inter zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "---"
echo "df6ewg4$"
./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "---"
echo "rien$"
./inter "rien" "cette phrase ne cache rien" | cat -e
echo "---"
echo "$"
./inter | cat -e
echo "---"
echo "$"
./inter "rien" | cat -e
echo "---"
echo "qwerty$"
./inter "qwerty" "qwertyyyyyyyyyyyyyy" | cat -e
echo "---"
echo "qwerty$"
./inter "qwertyyyyyyyyyyyyyy" "qwertyyyyyyyyyyyyyy" | cat -e
echo "---"
echo "qwerty$"
./inter "qqqqqqwertyyyyyyyyyyyyyy" "qqqqwertyyyyyyyyyyyyyy" | cat -e
echo "---"
echo "qwerty$"
./inter "qqqqqqwertyyyyyyyyyyyyyy" "qqqqwrertyyyyyyyyyyyyyy" | cat -e
echo "---"
echo "qwerty$"
./inter "qqqqqqwertyyyyyyyyrrrrrrrrrrrrrrrryyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwuuuuuuuuuuuuuuuuuuuuuuuuuuuqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyeeeeeeeeeeeeeeeeyyyyyy" "qqqqwrertyyyyyyyyyyyyyy" | cat -e
echo "---"
echo "q$"
./inter "qqqqqqwertyyyyyyyyyyyyyy" "q" | cat -e
echo "---"
echo "q$"
./inter "qqqqqqwertyyyyyyyyyyyyyy" "qqqqqqqqqqqqqqqqqqqqqqqqqqqq" | cat -e
echo "---"
echo "$"
./inter "aaaaaaaaaaaaaa" "bbbbbbbbbbbbbb" | cat -e
echo "---"
echo "1$"
./inter "1111111111111111" "122222222222222222222" | cat -e
echo "---"
echo "12$"
./inter "hahahah12" "kkkk12" | cat -e