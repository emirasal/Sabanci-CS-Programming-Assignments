import Router from "express";

import {
    getAllProds,
    getProductById,
    decreaseStock,
    clearCart
} from "../controllers/productController.js"

const router = Router();
router.get('/prodID/:id',getProductById)
router.get('/getAll', getAllProds)
router.get('/getAll', getAllProds)
router.get('/decreaseStock/:productId/:quantity', decreaseStock)

router.get('/clearCart/:userId', clearCart);
 
export {router};