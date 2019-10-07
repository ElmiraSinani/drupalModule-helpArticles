<?php

include_once 'services_help_articles.vo.inc';

function _services_help_articles_retrieve($type) {

	$result = new HelpArticle($type); 
	$query = new EntityFieldQuery();
	$entities = $query->entityCondition('entity_type', 'node')
		->propertyCondition('type', 'help_articles')
		->fieldCondition('field_cobol', 'value', $type, '=') 
		->execute();
	
	$content = (object) $entities['node'];
	$result->content = _services_help_articles_serialize_data($content); 

	return $result;
}


function _services_help_articles_serialize_data($data) {

   $result = array();

    foreach ($data as $k => $v) { 
	
		$items[$k] =  entity_load('node', False, array('nid' => $v->nid));

		foreach ($items[$k] as $key => $value) { 			
			$result[$value->vid]->node->nodeId = $value->vid;		
			$result[$value->vid]->node->cobolName = $value->field_cobol[und][0][value];
			$result[$value->vid]->node->title = $value->title;			
			$result[$value->vid]->node->description = $value->body[und][0][value];	
		}  
	}
	
 return $result;
} 