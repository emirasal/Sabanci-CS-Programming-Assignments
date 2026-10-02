import Product from '../models/productmodel.js'
import Cart from '../models/Cart.js'

const getAllProds = async(req,res)=>{
    const prods = await Product.find({})
    res.status(200).json(prods)
}

const getProductById = async (req,res)=>{
    try {
        const {id} = req.params //gives us the id that we type.

        const tprod = await Product.findById(id);
        if(!tprod){
            return res.status(404).json({error:"No corresponding product with given id."})
        }
        res.status(200).json(tprod);
    } catch (error) {
        console.error(error); 
        res.status(500).json({ error: "Internal server error" });
    }
}

const decreaseStock = async (req, res) => {
  const { productId, quantity } = req.params;
  try {
    const prod = await Product.findById(productId);
    // If there is enough stock to decrease
    if (prod.stock >= quantity) {
      const updatedProduct = await Product.findOneAndUpdate(
        { _id: productId },
        { $inc: { stock: -quantity } },
        { new: true }
      );
      return res.status(200).json(updatedProduct);
    } else {
      return res.status(400).json({ error: "Not enough stock." });
    }
  } catch (err) {
    return res.status(500).json({ error: "Error." });
  }
};

const clearCart = async (req, res) => {
  const { userId } = req.params;

  try {
    const updatedCart = await Cart.updateMany({ userId }, { $set: { products: [] } });

    return res.status(200).json({ message: "Cart cleared." });
  } catch (err) {
    return res.status(500).json({ error: "Error." });
  }
};

export {
    getAllProds,
    getProductById,
    decreaseStock,
    clearCart
};