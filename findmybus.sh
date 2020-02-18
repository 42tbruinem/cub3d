periodic() {
    while :; do
        ./cub3D ./scenes/scene.cub
		echo periodic
        date
        sleep 3
    done
}

main() {
    echo in the main...
    sleep 5
    echo still in the main...
    sleep 1
    echo in the main in the main in the main
}

periodic &
periodic_pid=$!

echo periodic_pid=$periodic_pid
main

echo time to stop
#kill $periodic_pid