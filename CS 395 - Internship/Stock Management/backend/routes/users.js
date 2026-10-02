import Router from "express";
import auth from "../middleware/auth.js";

import User from "../models/User.js";

const router = Router();

router.get("/details", auth, (req, res) => {
	res.status(200).json({ message: "user authenticated." });
});


router.get('/getUser/:id', async (req, res) => {
	try {
	  const user = await User.findById(req.params.id);
	  if (!user) {
		return res.status(404).json({ message: 'User not found' });
	  }
	  res.json(user);
	} catch (error) {
	  console.error(error);
	  res.status(500).json({ message: 'Server error' });
	}
  });
  

export default router;