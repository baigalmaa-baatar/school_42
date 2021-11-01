#include <mlx.h>

int	main(void)
{
	void	*mlx;
	//void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, 400, 400, "Hello world!");
	mlx_loop(mlx);
}
