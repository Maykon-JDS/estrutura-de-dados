<?php

declare(strict_types=1);

use Lista\class\Node;

use PHPUnit\Framework\TestCase;

use PHPUnit\Framework\Attributes\TestDox;

use PHPUnit\Framework\Attributes\CoversClass;


/**
 * @coversDefaultClass Lista\class\Node
 */
#[CoversClass(Node::class)]
#[TestDox("Node")]
class NodeTest extends TestCase
{

    /**
     * @covers Lista\class\Node::setValue
     */
    public function testGetValue(): void
    {

        $node = new Node(10);

        $this->assertEquals(10, $node->getValue());
    }

    /**
     * @covers Lista\class\Node::setValue
     */
    public function testSetValueInt(): void
    {

        $node = new Node(10);

        $node->setValue(25);

        $this->assertEquals(25, $node->getValue());
    }

    /**
     * @covers Lista\class\Node::setValue
     */
    public function testSetValueFloat(): void
    {

        $node = new Node(10);

        $node->setValue(2.55);

        $this->assertEquals(2.55, $node->getValue());
    }

    /**
     * @covers Lista\class\Node::setValue
     */
    public function testSetValueString(): void
    {

        $node = new Node(10);

        $node->setValue(25);

        $node->setValue("Testeeeee");

        $this->assertEquals("Testeeeee", $node->getValue());
    }


    /**
     * @covers Lista\class\Node::getNext
     */
    public function testGetNextNull(): void
    {

        $node = new Node(10);

        $this->assertNull($node->getNext());
    }

    /**
     * @covers Lista\class\Node::getNext
     */
    public function testGetNextNode(): void
    {

        $node1 = new Node(10);

        $node2 = new Node(23, $node1);

        $this->assertEquals($node1, $node2->getNext());
    }

    /**
     * @covers Lista\class\Node::setNext
     */
    public function testSetNextNull(): void
    {

        $node1 = new Node(10);

        $node2 = new Node(23, $node1);

        $node2->setNext(null);

        $this->assertNull($node2->getNext());
    }

    /**
     * @covers Lista\class\Node::setNext
     */
    public function testSetNextNode(): void
    {

        $node1 = new Node(10);

        $node2 = new Node(23, $node1);

        $node3 = new Node(99);

        $node2->setNext($node3);

        $this->assertEquals($node3, $node2->getNext());
    }
}
