gcc -Wall -Werror -Wextra union.c -o union
echo "# Expected result (next line) Your result #"
echo "------------01------------"
echo "zpadintoqefwjy$"
./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "------------02------------"
echo "df6vewg4thras$"
./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "------------03------------"
echo "rienct phas$"
./union "rien" "cette phrase ne cache rien" | cat -e
echo "------------04------------"
echo "$"
./union | cat -e
echo "------------05------------"
echo "$"
./union "rien" | cat -e
echo "------------06------------"
echo "qwerty$"
./union "qwerty" "qwertyyyyyyyyyyyyyy" | cat -e
echo "------------07------------"
echo "qwerty$"
./union "qwertyyyyyyyyyyyyyy" "qwertyyyyyyyyyyyyyy" | cat -e
echo "------------08------------"
echo "qwerty$"
./union "qqqqqqwertyyyyyyyyyyyyyy" "qqqqwertyyyyyyyyyyyyyy" | cat -e
echo "------------09------------"
echo "qwerty$"
./union "qqqqqqwertyyyyyyyyyyyyyy" "qqqqwrertyyyyyyyyyyyyyy" | cat -e
echo "------------10------------"
echo "qwertyu$"
./union "qqqqqqwertyyyyyyyyrrrrrrrrrrrrrrrryyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeyyyyyyyyyyyyyyyyyyyyyyyyyyyywwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwuuuuuuuuuuuuuuuuuuuuuuuuuuuqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwyyyyyyyyyyyyyyyyyyyyyyyeeeeeeeeeeeeeeeeyyyyyy" "qqqqwrertyyyyyyyyyyyyyy" | cat -e
echo "------------11------------"
echo "qwerty$"
./union "qqqqqqwertyyyyyyyyyyyyyy" "q" | cat -e
echo "------------12------------"
echo "qwerty$"
./union "qqqqqqwertyyyyyyyyyyyyyy" "qqqqqqqqqqqqqqqqqqqqqqqqqqqq" | cat -e
echo "------------13------------"
echo "ab$"
./union "aaaaaaaaaaaaaa" "bbbbbbbbbbbbbb" | cat -e
echo "------------14------------"
echo "12$"
./union "1111111111111111" "122222222222222222222" | cat -e
echo "------------15------------"
echo "ha12k$"
./union "hahahah12" "kkkk12" | cat -e
echo "------------16------------"
echo "qwerty$"
./union "qwerty" "ytrewq" | cat -e
