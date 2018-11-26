package fr.ensim.herbron.tp5.controller;

import fr.ensim.herbron.tp5.model.Article;
import fr.ensim.herbron.tp5.model.ArticleRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.Date;

@Controller
public class SubmitController {

    @Autowired
    ArticleRepository articleRepository;

    @GetMapping("/submit")
    public String submitForm(Model model) {
        model.addAttribute("submit", new Article());
        return "submit";
    }

    @PostMapping("/submit")
    public String submit(@ModelAttribute Article article)
    {

        article.setId(articleRepository.count() + 1);
        article.setCreation(new Date());
        articleRepository.save(article);
        return "success";
    }
}
