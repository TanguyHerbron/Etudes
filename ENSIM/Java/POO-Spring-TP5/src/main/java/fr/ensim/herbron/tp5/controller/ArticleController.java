package fr.ensim.herbron.tp5.controller;

import fr.ensim.herbron.tp5.model.ArticleRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class ArticleController {

    @Autowired
    ArticleRepository articleRepository;

    @GetMapping("/article")
    public String article(@RequestParam(name="artId")Long artId, Model model)
    {
        model.addAttribute("article", articleRepository.findById(artId).get());
        return "article";
    }
}
