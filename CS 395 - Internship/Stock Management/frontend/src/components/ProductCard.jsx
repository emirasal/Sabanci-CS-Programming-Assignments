import * as React from 'react';
import {Link} from "react-router-dom";
import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import CardMedia from '@mui/material/CardMedia';
import Typography from '@mui/material/Typography';
import {Button, CardActionArea, CardActions} from '@mui/material';
import {createTheme, ThemeProvider} from '@mui/material';
import bluegrey from "@mui/material/colors/grey"
import axios from "axios";

const theme = createTheme({
    palette: {
        primary: bluegrey,
    },
});

export default function MultiActionAreaCard({item}) {

    const handleAddToCart = async () => {

        let {userId} = localStorage;
        try {
            await axios.post('http://localhost:8080/api/addToCart', {
                productId: item._id
            }, {
                headers: {
                    userId: userId,
                }
            });

        } catch (error) {
            console.log('error')
        }
    }

    const price = parseFloat(item.price);

    return (

        <ThemeProvider theme={theme}>
            <Card sx={{maxWidth: 345}}>
                <CardActionArea component={Link}>
                    <CardMedia
                        component="img"
                        height="210"
                        image={item.image}
                        alt="Product"
                    />
                    <CardContent>
                        <Typography gutterBottom variant="h5" component="div">
                            {item.Pname}
                        </Typography>
                        <Typography variant="body2" color="text.secondary">
                            ${price}
                        </Typography>
                    </CardContent>
                </CardActionArea>
                <CardActions>
                {item.stock > 0 ? (
                        <Button variant="contained" onClick={handleAddToCart} >Add to Cart</Button>  
                        ): (
                        <Button variant="contained" color="error" disabled>Out of Stock</Button>  
                        )
                }
                </CardActions>
            </Card>
        </ThemeProvider>
    );
}