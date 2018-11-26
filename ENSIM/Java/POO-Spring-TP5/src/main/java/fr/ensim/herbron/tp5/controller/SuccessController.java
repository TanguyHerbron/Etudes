package fr.ensim.herbron.tp5.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class SuccessController {

    @GetMapping("/success")
    public String success()
    {
        return "success";
    }
}
