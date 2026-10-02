import express from "express";
import { createGig, deleteGig, getGig, getGigs } from "../controllers/gig.js";
import { verifyToken } from "../middleware/jwt.js";


const router = express.Router();

router.post("/create", verifyToken, createGig);
router.delete("/delete/:id", verifyToken, deleteGig);
router.get("/getGig/:id", getGig);
router.get("/getGigs", getGigs);

export default router;