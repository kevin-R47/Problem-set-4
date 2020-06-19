void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;

            int count = 0;

            if (j >= 0 )
            {
                red += image[i][j].rgbtRed;
                green += image[i][j].rgbtGreen;
                blue += image[i][j].rgbtBlue;
                count++;
            }

            if (j - 1 >= 0 && j - 1  < width- 1)
            {
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                count++;
            }

            if (j + 1 >= 0 && j + 1  < width - 1)
            {
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                count++;
            }

            if (j - 1 >= 0 && j - 1  < width - 1 && i - 1 >= 0 && i - 1 < height - 1)
            {
                red += image[i - 1][j - 1].rgbtRed;
                green += image[i - 1][j - 1].rgbtGreen;
                blue += image[i - 1][j - 1].rgbtBlue;
                count++;
            }

            if (i - 1 >= 0 && i - 1 < height - 1)
            {
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                count++;
            }

            if (j + 1 >= 0 && j + 1  < width - 1 && i - 1 >= 0 && i - 1 < height - 1)
            {
                red += image[i - 1][j + 1].rgbtRed;
                green += image[i- 1][j + 1].rgbtGreen;
                blue += image[i- 1][j + 1].rgbtBlue;
                count++;
            }

            if (j - 1 >= 0 && j - 1  < width - 1 && i + 1 >= 0 && i + 1 < height - 1)
            {
                red += image[i + 1][j - 1].rgbtRed;
                green += image[i + 1] [j - 1].rgbtGreen;
                blue += image[i + 1][j - 1].rgbtBlue;
                count++;
            }

            if (i + 1 >= 0 && i + 1 < height - 1)
            {
                red += image[i+ 1][j ].rgbtRed;
                green += image[i+ 1][j].rgbtGreen;
                blue += image[i+ 1][j].rgbtBlue;
                count++;
            }

            if (j + 1 >= 0 && j + 1  < width- 1 && i + 1 >= 0 && i + 1 < height - 1)
            {
                red += image[i + 1][j + 1].rgbtRed;
                green += image[i+ 1][j + 1].rgbtGreen;
                blue += image[i+ 1][j + 1].rgbtBlue;
                count++;
            }

            copy[i][j].rgbtRed = round(red / count);
            copy[i][j].rgbtGreen = round(green / count);
            copy[i][j].rgbtBlue = round(blue / count);


        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}