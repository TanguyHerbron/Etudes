package fr.ensim.herbron.tp5.model;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ArticleRepository  extends CrudRepository<Article , Long>
{

}
