
#include "ft_printf.h"

int 	ft_get_padding(t_data *data, char const *str, int i)
{
	int	j;
	char *temp_number;

	if (str[i] == '0' && dot != 1 && data.minus_flag == false && data.character == 'd' || data.character == 'i' || data.character == 'u')
		data.zero_flag = true;
	if (str[i] == '0' || str[i] == '.')
		i++;
	j = i;
	while (str[j] != data->character || str[j] != '.')
		j++;
	temp_number = ft_str
	data->left_padding = ft_atoi(temp_number);
	free(temp_number);
	while (str[j] != data->character)
		j++;
	temp_number = malloc(j - i + 1);
	data->right_padding = ft_atoi(temp_number);
	free(temp_number);
	return (j - 1);
}

void	ft_get_flags(char const *str, va_list lst, t_data *data, int s)
{
	ft_clean_struct(&data);
	if (data->character == '%')
		return ;
	while (str[++i] != data.character)
	{
		if (str[i] == '#' && (data.character == 'x' || data.character == 'X'))
			data.hex_flag = true;
		if (str[i] == '+' && (data.character == 'd' || data.character == 'i' || data.character == 'u'))
		{
			data->plus_flag = true;
			if (data.space_flag == true)
				data.space_flag = false;
		}
		if (str[i] == ' ' && data.plus_flag == false)
			data.space_flag = true;
		if (str[i] == '-')
		{
			data.minus_flag = true;
			if (data.zero_flag == true)
				data.zero_flag = false;
		}
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			i = ft_get_padding(data, str, i);
	}
}