./params.sh echo test     \    test
./params.sh echo \"test
./params.sh echo $USER
./params.sh echo "$USER"
./params.sh "echo '$USER'"
./params.sh echo "$USER$USER$USER"
./params.sh echo "$USER$USER=lol$USER"
./params.sh echo "   $USER lol $USER"
./params.sh echo $USER$USER$USER
./params.sh echo $USER$USER=lol$USER""lol
./params.sh echo    $USER lol $USER
./params.sh echo test "" test "" test
./params.sh echo \
./params.sh echo "$=USER"
./params.sh echo "$"
./params.sh echo "$?"
./params.sh echo $USER $USER
# ./params.sh echo "$1USER" need to update!!!!!!
./params.sh echo "$U1USER"