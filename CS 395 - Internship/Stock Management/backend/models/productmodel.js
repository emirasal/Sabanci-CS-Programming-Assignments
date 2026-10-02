import mongoose from "mongoose"

const productSchema = new mongoose.Schema({
    Pname: {
        type: String,
        required: true
    },
    price: {
        type: Number,
        required: true
    },
    stock:{
        type: Number,
        required: true
    },
    image: {
        type: String
    },
},{timestamps:true})

const Product = mongoose.model("Product", productSchema);

export default Product;